#ifndef XTHREE_L_O_D_HPP
#define XTHREE_L_O_D_HPP

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
    // l_o_d declaration
    //

    template<class D>
    class xl_o_d : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xl_o_d();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using l_o_d = xw::xmaterialize<xl_o_d>;

    using l_o_d_generator = xw::xgenerator<xl_o_d>;

    //
    // l_o_d implementation
    //


    template <class D>
    inline void xl_o_d<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xl_o_d<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xl_o_d<D>::xl_o_d()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xl_o_d<D>::set_defaults()
    {
        this->_model_name() = "LODModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xl_o_d>& widget)
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
        extern template class xw::xmaterialize<xthree::xl_o_d>;
        extern template xw::xmaterialize<xthree::xl_o_d>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xl_o_d>>;
        extern template class xw::xgenerator<xthree::xl_o_d>;
        extern template xw::xgenerator<xthree::xl_o_d>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xl_o_d>>;
    #endif
#endif

#endif