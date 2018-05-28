#ifndef XTHREE_UNIFORM_HPP
#define XTHREE_UNIFORM_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../base/xenums.hpp"
#include "../base/xthree_types.hpp"
#include "../base/xthree.hpp"
#include "../base/xrender.hpp"

namespace xthree
{
    //
    // uniform declaration
    //

    template<class D>
    class xuniform : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xuniform();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using uniform = xw::xmaterialize<xuniform>;

    using uniform_generator = xw::xgenerator<xuniform>;

    //
    // uniform implementation
    //


    template <class D>
    inline void xuniform<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xuniform<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xuniform<D>::xuniform()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xuniform<D>::set_defaults()
    {
        this->_model_name() = "UniformModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xuniform>& widget)
    {
        if (not widget.pre)
            widget.pre = std::make_shared<preview>(preview(widget));
        return mime_bundle_repr(*widget.pre);
    }
}

/*********************
 * precompiled types *
 *********************/

#ifdef PRECOMPILED
    #ifndef _WIN32
        extern template class xw::xmaterialize<xthree::xuniform>;
        extern template xw::xmaterialize<xthree::xuniform>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xuniform>>;
        extern template class xw::xgenerator<xthree::xuniform>;
        extern template xw::xgenerator<xthree::xuniform>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xuniform>>;
    #endif
#endif

#endif