#ifndef XTHREE_SHAPE_UTILS_HPP
#define XTHREE_SHAPE_UTILS_HPP

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
    // shape_utils declaration
    //

    template<class D>
    class xshape_utils : public xthree_widget<D>
    {
    public:

        using base_type = xthree_widget<D>;
        using derived_type = D;

        void serialize_state(xeus::xjson&, xeus::buffer_sequence&) const;
        void apply_patch(const xeus::xjson&, const xeus::buffer_sequence&);



        std::shared_ptr<xw::xmaterialize<xpreview>> pre = nullptr;

    protected:

        xshape_utils();
        using base_type::base_type;
        
    private:

        void set_defaults();
    };

    using shape_utils = xw::xmaterialize<xshape_utils>;

    using shape_utils_generator = xw::xgenerator<xshape_utils>;

    //
    // shape_utils implementation
    //


    template <class D>
    inline void xshape_utils<D>::serialize_state(xeus::xjson& state, xeus::buffer_sequence& buffers) const
    {
        base_type::serialize_state(state, buffers);

    }

    template <class D>
    inline void xshape_utils<D>::apply_patch(const xeus::xjson& patch, const xeus::buffer_sequence& buffers)
    {
        base_type::apply_patch(patch, buffers);

    }

    template <class D>
    inline xshape_utils<D>::xshape_utils()
        : base_type()
    {
        set_defaults();
    }

    template <class D>
    inline void xshape_utils<D>::set_defaults()
    {
        this->_model_name() = "ShapeUtilsModel";
        this->_view_name() = "";
    }

    xeus::xjson mime_bundle_repr(xw::xmaterialize<xshape_utils>& widget)
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
        extern template class xw::xmaterialize<xthree::xshape_utils>;
        extern template xw::xmaterialize<xthree::xshape_utils>::xmaterialize();
        extern template class xw::xtransport<xw::xmaterialize<xthree::xshape_utils>>;
        extern template class xw::xgenerator<xthree::xshape_utils>;
        extern template xw::xgenerator<xthree::xshape_utils>::xgenerator();
        extern template class xw::xtransport<xw::xgenerator<xthree::xshape_utils>>;
    #endif
#endif

#endif