#ifndef XTHREE_PATH_HPP
#define XTHREE_PATH_HPP

#include "xtl/xoptional.hpp"
#include "xwidgets/xeither.hpp"
#include "xwidgets/xwidget.hpp"

#include "../../base/xenums.hpp"
#include "../../base/xthree_types.hpp"
#include "../../base/xthree.hpp"
#include "../../base/xrender.hpp"

namespace xthree
{
    //
    // path declaration
    //

    template<class D>
    class xpath : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xpath();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using path = xw::xmaterialize<xpath>;

    using path_generator = xw::xgenerator<xpath>;

    //
    // path implementation
    //


    template <class D>
    inline void xpath<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xpath<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xpath<D>::xpath()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xpath<D>::set_defaults()
    {
        this->_model_name() = "PathModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xpath>& widget)
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
        extern template class xw::xmaterialize<xthree::xpath>;
        extern template xw::xmaterialize<xthree::xpath>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xpath>>;
        extern template class xw::xgenerator<xthree::xpath>;
        extern template xw::xgenerator<xthree::xpath>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xpath>>;
    #endif
#endif

#endif